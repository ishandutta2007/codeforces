#include <bits/stdc++.h>

using namespace std;

int n;
double rub[5001],euro[5001],dol[5001],a,b;
set<string> st;
string s1,str,str1;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>str;
    str1=str;
    do {
        st.insert(str);
        s1.clear();
        s1+=str[0];
        str.erase(str.begin());
        str+=s1;
    } while (str1!=str);

    cout<<st.size();


    return 0;
}