#include<bits/stdc++.h>
using namespace std;
const int maxn = 45000;

int main()
{
	int up[maxn];
	up[0]=0;
	for(int i=1;i<maxn;i++)
    {
        up[i]=up[i-1]+i;
    }


	int t;
	cin>>t;
	while(t--)
    {
        int arr[maxn]={0};
        printf("13");
        int n;
        cin>>n;
        for(int i=maxn-1;i;i--)
        {
            while(n>=up[i])
            {
                n-=up[i];
                arr[i]++;
            }
        }

        for(int i=1;i<maxn;i++)
        {
            printf("3");
            for(int j=0;j<arr[i];j++)printf("7");
        }
        puts("");
    }
	return 0;
}