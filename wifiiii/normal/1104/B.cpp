#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;
const ll mod = 1e9+7;

stack<char> st;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<s.size();++i)
    {
        st.push(s[i]);
        while(!st.empty())
        {
            char c1 = st.top();st.pop();
            if(!st.empty() && c1==st.top()) {st.pop();cnt++;}
            else {st.push(c1);break;}
        }
    }
    if(cnt%2) cout<<"Yes\n";
    else cout <<"No\n";
}