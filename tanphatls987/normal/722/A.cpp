#include <bits/stdc++.h>

using namespace std;

int type;
string s;
bool check(string s){
    int hh=(s[0]-'0')*10+s[1]-'0';
    int mm=(s[3]-'0')*10+s[4]-'0';
    if ((mm>=60)) return 0;
    if (type==12) return (1<=hh&&hh<=12);
    return hh<24;
}
string tostring(int hh,int mm){
    string ans;
    ans.push_back(hh/10+'0');
    ans.push_back(hh%10+'0');
    ans=ans+":";
    ans.push_back(mm/10+'0');
    ans.push_back(mm%10+'0');
    return ans;
}
string solve(){
    string ans;
    int use=10;
    for(int hh=0;hh<=23;hh++)
        for(int mm=0;mm<60;mm++){
            string cur=tostring(hh,mm);
            int val=0;
            for(int i=0;i<5;i++) val+=s[i]!=cur[i];
            if (check(cur)&&val<use){
                use=val;
                ans=cur;
            }
        }
    return ans;
}
int main(){
    cin>>type>>s;
//    cout<<type<<'\n';
    cout<<solve();
}