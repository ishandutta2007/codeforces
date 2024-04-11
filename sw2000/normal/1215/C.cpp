#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int arr[maxn];

int main()
{
    int n,ca1=0,ca2=0;
    scanf("%d",&n);
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        if(s1[i]=='a'&&s2[i]=='b')
        {
            arr[i]=1;
            ca1++;
        }
        if(s1[i]=='b'&&s2[i]=='a')
        {
            arr[i]=-1;
            ca2++;
        }
    }
    if((ca1+ca2)%2==1)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        if(ca2%2==1)cout<<(ca2+ca1)/2+1<<endl;
        else cout<<(ca2+ca1)/2<<endl;
        int la1=-1,la2=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                if(la1==-1)
                {
                    la1=i;
                }
                else
                {
                    printf("%d %d\n",la1+1,i+1);
                    la1=-1;
                }
            }
            if(arr[i]==-1)
            {
                if(la2==-1)
                {
                    la2=i;
                }
                else
                {
                    printf("%d %d\n",la2+1,i+1);
                    la2=-1;
                }
            }
        }
        if(la1!=-1)
        {
            printf("%d %d\n",la1+1,la1+1);
            printf("%d %d\n",la2+1,la1+1);
        }
    }
    return 0;
}