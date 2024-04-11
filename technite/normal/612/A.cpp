#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
void printarray(int a[], int n)
{
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
void printvector(vector<int> v)
{
	for (auto x : v)
		cout<<x<<" ";
	cout<<"\n";
}
int main()  
{  
    int n, p, q;  
    scanf("%d%d%d",&n,&p,&q); 
    char str[110]; 
	scanf("%s",str);
	bool flag = false;  
    for(int i = 0; i <= n; i++)  
    {  
        for(int j = 0; j <= n; j++)  
        {  
            if(i * p + j * q == n)  
            {  
                printf("%d\n",i+j);
				  
                for(int k = 0; k < i; k++)  
                {  
                    for(int l = k*p; l < (k+1)*p; l++)  
                        printf("%c", str[l]);  
                    printf("\n");  
                }  
                for(int k = 0; k < j; k++)  
                {  
                    for(int l = i*p + k*q; l < (k+1)*q + i*p; l++)  
                        printf("%c", str[l]);  
                    printf("\n");  
                }  
                flag = true;  
                break;  
            }  
        }  
        if(flag)  
            break;  
    }  
    if(!flag)  
        printf("-1\n");

}