#include <bits/stdc++.h>
using namespace std;

int z[50005];
pair<double, int> arr[50005];
int ans[50005];
int n;

const double PI = acos(-1);
double c, s;
double c2, s2;
double angle;

// 2n   ?

double area(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
  return abs(a.first * b.second + b.first * c.second + c.first * a.second -
    b.first * a.second - c.first * b.second - a.first * c.second);
}

double process(int X, int Y)
{
  pair<double, double> pt3(n + n * c, n * s);

  pair<double, double> L(X, 0);
  pair<double, double> R(pt3.first + Y * c2, pt3.second + Y * s2);

  pair<double, double> F(n, 0);
  pair<double, double> S(n + (n - 1) * c, (n - 1) * s);

  return area(L, R, S) - area(L, R, F);
}

int main()
{
  scanf("%d",&n);
  for (int i = 0; i < n; i++) 
  {
    scanf("%d", &z[i]);
  }
  z[n] = z[0];

  angle = PI / n;
  c = cos(angle);
  s = sin(angle);
  c2 = cos(angle * 2);
  s2 = sin(angle * 2);

  for (int i = 0; i < n; i++)
  {
    arr[i].second = i;
    arr[i].first = process(z[i], z[i + 1]);
  }

  sort(arr, arr + n);

  for (int i = 0; i < n; i++) ans[arr[i].second] = i;
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  printf("\n");
}