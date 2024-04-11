#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,a[N],le[N],ri[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]>a[i]) 
			st.pop();
        if(!st.empty()) 
			le[i]=st.top();
        else
			le[i]=0;
        while(!st.empty()&&a[st.top()]==a[i]) 
			st.pop();
        st.push(i);
    }
    while(!st.empty()) 
		st.pop();
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]>=a[i]) 
			st.pop();
        if(!st.empty()) 
			ri[i]=st.top();
        else 
			ri[i]=n+1;
        st.push(i);
    }
    int minsum=0;
    for(int i=1;i<=n;i++)
        minsum+=a[i]*(i-le[i])*(ri[i]-i);
    while(!st.empty()) 
		st.pop();
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]<a[i]) 
			st.pop();
        if(!st.empty()) 
			le[i]=st.top();
        else 
			le[i]=0;
        while(!st.empty()&&a[st.top()]==a[i]) 
			st.pop();
        st.push(i);
    }
    while(!st.empty()) 
		st.pop();
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i]) 
			st.pop();
        if(!st.empty()) 
			ri[i]=st.top();
        else 
			ri[i]=n+1;
        st.push(i);
    }
    int maxsum=0;
    for(int i=1;i<=n;i++)
        maxsum+=a[i]*(i-le[i])*(ri[i]-i);
    cout<<maxsum-minsum<<endl;
    return 0;
}