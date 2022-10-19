#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int x[maxn];
int cnt(double s)
{
    int tp=0;
    for(int i=1;i<maxn;++i)
    {
        tp+=x[i];
        if(tp>s)
        {
            return i;
        }
    }
}
int judge(int sign)
{
    int tp=0;
    for(int i=1;i<sign;++i)
    {
        tp+=x[i];
    }
    return tp;
}
int main()
{
    int n;
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
    	cin>>x[i];
        sum+=x[i];
    }
    int sign=cnt(sum/2.0);
    sum-=x[sign];
    int tp=judge(sign);
    if(tp>sum/2.0)
	{
    	--sign;
    }
    cout<<sign<<" "<<n-sign;
    return 0;
}