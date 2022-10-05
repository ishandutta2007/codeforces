#include<bits/stdc++.h>
#define ll long long

class matrix{
private:
	int a[2][2];
	int moder = 0;
	
public:
	matrix (){memset(a, 0, sizeof(a));}
	matrix (int moder):moder(moder){memset(a, 0, sizeof(a));}
	int *operator [](int n){return a[n];}
	void setmod(int moder){this -> moder = moder;}
	
	matrix operator * (const matrix &p)const &{
		matrix ret(moder);
		for (int k = 0; k < 2; ++ k){
			for (int i = 0; i < 2; ++ i){
				for (int j = 0; j < 2; ++ j){
					ret.a[i][j] = (ret.a[i][j] + 1ll * a[i][k] * p.a[k][j]) % moder;
				}
			}
		}
		return ret;
	}
	
	template <typename K>
	matrix power(K exp)const &{
		matrix ret(moder), aux(*this);
		ret.a[0][0] = ret.a[1][1] = 1;
		for ( ; exp; exp >>= 1){
			if (exp & 1){
				ret = ret * aux;
			}
			aux = aux * aux;
		}
		return ret;
	}

	void print(){
		for (int i = 0; i < 2; ++ i){
			for (int j = 0; j < 2; ++ j){
				printf("%d%c", a[i][j], " \n"[j]);
			}
		}
		putchar('\n');
	}
};

const int MAX = 1 << 16;
const int N = 50010;

int n, m, p;
ll k;
int s[N];
std::pair <ll, int> q[N];
matrix seg[MAX << 1];

void build(){
	for (int i = 0; i < MAX << 1; ++ i){
		seg[i].setmod(p);
		seg[i][0][0] = seg[i][1][1] = 1;
	}
}

void add(int sit, matrix p){
	seg[sit += MAX] = p;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = seg[sit << 1 | 1] * seg[sit << 1];
	}
}

matrix query(int l, int r){
	matrix mat(p);
	mat[0][0] = mat[1][1] = 1;
	matrix mat1 = mat;
	if (l > r) return mat;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			mat = seg[l ++] * mat;
		}
		if (r & 1){
			mat1 = mat1 * seg[-- r];
		}
	}
	return mat1 * mat;
}

int main(){
	scanf("%I64d%d%d", &k, &p, &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &s[i]);
	}
	build();
	for (int i = 0; i < n; ++ i){
		matrix mat(p);
		mat[0][1] = 1;
		mat[1][0] = s[i];
		mat[1][1] = s[(i + 1) % n];
		add(i, mat);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++ i){
		ll j;
		int v;
		scanf("%I64d%d", &j, &v);
		q[i] = {j, v};
	}
	if (!k){
		return printf("0\n"), 0;
	}	
	std::sort(q, q + m);
	while (m && q[m - 1].first >= k){
		-- m;
	}
	if (q[m - 1].first != k - 1){
		q[m ++] = {k - 1, s[(k - 1) % n]};
	}
	ll now = 0;
	matrix nowmat(p);
	nowmat[0][0] = nowmat[1][1] = 1;
	for (int i = 0; i < m; ++ i){
		matrix mat(p);
		if (now / n >= (q[i].first - 2) / n){
			if (now <= q[i].first - 2){
				mat = query(now % n, (q[i].first - 2) % n);
				nowmat = mat * nowmat;
			}
		}
		else{
			mat = query(now % n, n - 1);
			nowmat = mat * nowmat;
			mat = query(0, n - 1);
			mat = mat.power <ll> ((q[i].first - 2) / n - now / n - 1);
			nowmat = mat * nowmat;
			mat = query(0, (q[i].first - 2) % n);
			nowmat = mat * nowmat;
			now = q[i].first - 1;
		}
		//nowmat.print();
		if (now < q[i].first){
			mat[0][0] = 0;
			mat[0][1] = 1;
			mat[1][0] = s[(q[i].first - 1) % n];
			mat[1][1] = q[i].second;
			//mat.print();
			nowmat = mat * nowmat;
		}
		//nowmat.print();
		mat[0][0] = 0;
		mat[0][1] = 1;
		mat[1][0] = q[i].second;
		mat[1][1] = i < m - 1 && q[i].first + 1 == q[i + 1].first ? q[i + 1].second : s[(q[i].first + 1) % n];
		nowmat = mat * nowmat;
		now = q[i].first + 1;
	}
	for (int i = 0; i < 28; ++ i){
	    int *ptr = new int[1000000]();
	    delete []ptr;
	}
	printf("%d\n", nowmat[0][1]);
	return 0;
}