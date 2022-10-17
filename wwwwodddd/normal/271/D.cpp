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
typedef unsigned long long ll;
const int N = 1509, Z = 125;
ll P[N], S[N];
ll H(int l, int r)
{
    return S[r+1] - S[l] * P[r-l+1];
}


struct H{
    const static int P = 3214567, N = 3214567;
    int head[P], next[N];
	ll key[N];
    int sz;
    inline int size(){
        return sz;
    }

    inline bool find(ll val){
        int x = val % P;
        for (int i=head[x]; i; i=next[i])
            if (key[i] == val) return true;
        return false;
    }

    inline void insert(ll val){
        ++sz; key[sz] = val;
        int x = val % P; next[sz] = head[x]; head[x] = sz;
    }
} hashh;

char str[N]; bool good[N];
int n, k;


int main(){
	scanf("%s",str);
    int n = strlen(str);
    P[0] = S[0] = 1;
	fo(i,n)
	P[i] = P[i-1] * Z;
	fr(i,n)S[i+1] = S[i] * Z + str[i];
    fr(i,26)
    {
		char cc;
		cin>>cc;
		good[i] = cc == '1';
	}
	cin>>k;
	fr(i,n)
	{
        int kk = k;
        for(int j=i;j<n;j++)
		{
            if (!good[str[j]-'a']) if (!kk--) break;
            if (!hashh.find(H(i, j))){
                hashh.insert(H(i, j));
                //cout << i << " " << j << endl;
            }
        }
    }
    cout << hashh.sz;
}