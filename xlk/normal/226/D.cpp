#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
const int N = 109;
int a[N][N]; 
long long r[N], c[N];
bool rr[N], cc[N];
int n, m;
vector<int> R,C;
int main()
{
	cin>>n>>m;
	fr(i,n)
		fr(j,m)
		{
			cin>>a[i][j];
			r[i]+=a[i][j];
			c[j]+=a[i][j];
		}
    while (true)
	{
        long long t = 1LL<<60;
		bool flag = true;
		int h;
        fr(i,n) if (r[i] < t) h = i, t = r[i];
        fr(i,m) if (c[i] < t) h = i, t = c[i], flag = false;

        if (t >= 0) break;

        if (flag){
            rr[h] ^= 1;
            r[h] = -r[h];
            int i = h;
            fr(j,m)
            {
                c[j] -= a[i][j];
                a[i][j] = - a[i][j];
                c[j] += a[i][j];
            }
        }
        else {
            cc[h] ^= 1;
            c[h] = -c[h];
            int j = h;
            fr(i,n)
            {
                r[i] -= a[i][j];
                a[i][j] = - a[i][j];
                r[i] += a[i][j];
            }
        }
    }

	fr(i,n)
		if (rr[i]) R.push_back(i+1);
	fr(i,m)
    	if (cc[i]) C.push_back(i+1);


    cout << R.size() << " ";
	fe(i,R)
		cout<<*i<<' '; 
    cout << endl;
    cout << C.size() << " ";
	fe(i,C)
		cout<<*i<<' '; 
    cout << endl;
}