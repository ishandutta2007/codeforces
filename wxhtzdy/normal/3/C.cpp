#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=3;
string s[N];
bool checkx(){
    if(s[0][0]=='X'&&s[0][1]=='X'&&s[0][2]=='X')return true;
    if(s[1][0]=='X'&&s[1][1]=='X'&&s[1][2]=='X')return true;
    if(s[2][0]=='X'&&s[2][1]=='X'&&s[2][2]=='X')return true;
    if(s[0][0]=='X'&&s[1][0]=='X'&&s[2][0]=='X')return true;
    if(s[0][1]=='X'&&s[1][1]=='X'&&s[2][1]=='X')return true;
    if(s[0][2]=='X'&&s[1][2]=='X'&&s[2][2]=='X')return true;
    if(s[0][0]=='X'&&s[1][1]=='X'&&s[2][2]=='X')return true;
    if(s[0][2]=='X'&&s[1][1]=='X'&&s[2][0]=='X')return true;
    return false;
}
bool checky(){
    if(s[0][0]=='0'&&s[0][1]=='0'&&s[0][2]=='0')return true;
    if(s[1][0]=='0'&&s[1][1]=='0'&&s[1][2]=='0')return true;
    if(s[2][0]=='0'&&s[2][1]=='0'&&s[2][2]=='0')return true;
    if(s[0][0]=='0'&&s[1][0]=='0'&&s[2][0]=='0')return true;
    if(s[0][1]=='0'&&s[1][1]=='0'&&s[2][1]=='0')return true;
    if(s[0][2]=='0'&&s[1][2]=='0'&&s[2][2]=='0')return true;
    if(s[0][0]=='0'&&s[1][1]=='0'&&s[2][2]=='0')return true;
    if(s[0][2]=='0'&&s[1][1]=='0'&&s[2][0]=='0')return true;
    return false;
}
int main(){
    for(int i=0;i<N;i++)cin>>s[i];
    int cx=0,cy=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cx+=s[i][j]=='X';
            cy+=s[i][j]=='0';
        }
    }
    if(cx-cy<0||cx-cy>1||(checkx()&&checky())||(checkx()&&cx==cy)||(checky()&&cx>cy)){cout<<"illegal";return 0;}
    if(checkx()){cout<<"the first player won";return 0;}
    if(checky()){cout<<"the second player won";return 0;}
    if(cx+cy==9){cout<<"draw";return 0;}
    if(cx==cy){cout<<"first";return 0;}
    if(cx>cy){cout<<"second";return 0;}
    return 0;
}