#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = 4 * atan(1);
const int N = 1 << 19;
int n;
int q;

struct Matrix
{
	double a[3][3];

	Matrix()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				a[i][j] = (int)(i == j);
	}

	Matrix operator * (const Matrix &A) const
	{
		Matrix R = Matrix();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				R.a[i][j] = 0;
				for (int h = 0; h < 3; h++)
					R.a[i][j] += a[i][h] * A.a[h][j];
			}
		return R;
	}
};

Matrix getShift(double dx, double dy)
{
	Matrix R = Matrix();
	R.a[0][0] = R.a[1][1] = R.a[2][2] = 1;
	R.a[2][0] = dx;
	R.a[2][1] = dy;
	return R;
}
Matrix getRotate(double x, double y, double ang)
{
	Matrix R = Matrix();
	R.a[2][0] = R.a[2][1] = R.a[0][2] = R.a[1][2] = 0;
	R.a[2][2] = 1;
	R.a[0][0] = cos(ang);
	R.a[1][0] = -sin(ang);
	R.a[0][1] = sin(ang);
	R.a[1][1] = cos(ang);
	return getShift(-x, -y) * R * getShift(x, y);
}

struct Node
{
	int l, r;
	Matrix A;

	Node () : l(), r(), A() {}
	Node(int _l, int _r) : l(_l), r(_r) {}
};

Node tree[2 * N];

void buildTree()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
	return;
}

void push(int v)
{
	if (v >= N) throw;
	for (int i = 0; i < 2; i++)
		tree[2 * v + i].A = tree[2 * v + i].A * tree[v].A;
	tree[v].A = Matrix();
	return;
}

void apply(int v, int l, int r, Matrix A)
{
	if (l <= tree[v].l && tree[v].r <= r)
	{
		tree[v].A = tree[v].A * A;
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int i = 0; i < 2; i++)
		apply(2 * v + i, l, r, A);
	return;
}

Matrix getVal(int p)
{
	int v = 1;
	while(v < N)
	{
		push(v);
		v *= 2;
		if (p >= tree[v].r) v++;
	}
	return tree[v].A;
}

void query1(int p, double L)
{
	Matrix A = getVal(p);
	Matrix B = getVal(p + 1);
	double x = B.a[0][0] - A.a[0][0], y = B.a[0][1] - A.a[0][1];
	L /= sqrt(x * x + y * y);
	x *= L;
	y *= L;
	apply(1, p + 1, n + 1, getShift(x, y));
	return;
}
void query2(int p, double ang)
{
	Matrix A = getVal(p);
	apply(1, p + 1, n + 1, getRotate(A.a[0][0], A.a[0][1], ang));
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	buildTree();
	for (int i = 0; i <= n; i++)
	{
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				tree[N + i].A.a[x][y] = 0;
		tree[N + i].A.a[0][0] = i;
		tree[N + i].A.a[0][2] = 1;
	}
	while(q--)
	{
		int t, pos;
		scanf("%d%d", &t, &pos);
		if (t == 1)
		{
			double len;
			scanf("%lf", &len);
			query1(pos - 1, len);
		}
		else
		{
			double ang;
			scanf("%lf", &ang);
			ang = (360. - ang) / 180. * PI;
			query2(pos - 1, ang);
		}
		Matrix R = getVal(n);
		printf("%.10lf %.10lf\n", R.a[0][0], R.a[0][1]);
	}

	return 0;
}