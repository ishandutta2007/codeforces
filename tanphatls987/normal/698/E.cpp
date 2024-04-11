#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const ll linf=1e16;
const int MOD=1e9+7;
const int N=5e4+10;
const int totalmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const int styr=1970;
const ll daysec=24*60*60;

ll psumd[N];
struct info{
    int wday,year,month,date,hh,mm,ss;
    info (int _wday=0,int _year=0,int _month=0,int _date=0,int _hh=0,int _mm=0,int _ss=0){
        wday=_wday,year=_year,month=_month,date=_date,hh=_hh,mm=_mm,ss=_ss;
    }
    void print(){
        cout<<year<<" "<<month<<" "<<date<<" "<<wday<<" "<<hh<<" "<<mm<<" "<<ss<<'\n';
    }
};
info piv,best;
int leapyear(int year){
    if (year%100==0) return year%400==0;
    return year%4==0;
}
int monthday(int month,int year){
    if (month==1&&leapyear(year)) return 29;
    return totalmonth[month];
}

info sectoinfo(ll val){
    info ans;
    ans.wday=(val/daysec+3)%7;
    ans.year=(upper_bound(psumd,psumd+N,val/daysec)-psumd-1)+styr;
//    cout<<psumd[ans.year-styr]<<" "<<val/daysec<<'\n';
    val-=psumd[ans.year-styr]*daysec;
    ///
    ans.month=0;
    while (1){
        ll subtime=monthday(ans.month,ans.year)*daysec;
        if (val<subtime) break;
        val-=subtime;
        ans.month++;
    }
    ans.date=val/daysec;
    val%=daysec;
    ans.hh=val/3600;
    val%=3600;
    ans.mm=val/60;
    ans.ss=val%60;
    return ans;
}
ll infotosecs(info a){
    ll ans=psumd[a.year-styr]*daysec+a.date*daysec;
    for(int i=0;i<a.month;i++) ans+=monthday(i,a.year)*daysec;
    ans+=a.hh*3600+a.mm*60+a.ss;
    return ans;
}
info addsec(info cur,ll val){
    return sectoinfo(infotosecs(cur)+val);
}
ll btime;
void prepare(){
    REP(i,1,N) psumd[i]=psumd[i-1]+365+leapyear(styr+i-1);
    ///
    scanf("%d%d%d%d%d%d",&piv.ss,&piv.mm,&piv.hh,&piv.wday,&piv.date,&piv.month);
    piv.year=styr;
    if (piv.date!=-1) piv.date--;
    if (piv.month!=-1) piv.month--;
    if (piv.wday!=-1) piv.wday--;
    best=piv;
    if (best.hh==-1) best.hh=0;
    if (best.ss==-1) best.ss=0;
    if (best.mm==-1) best.mm=0;
}
int checkdate(info cur){
    if (piv.month!=-1&&cur.month!=piv.month) return 0;
    return 1;
}
int checkwday(info cur){
    if (piv.date!=-1&&piv.wday!=-1)
        return (cur.date==piv.date||cur.wday==piv.wday);
    if (piv.date!=-1&&cur.date!=piv.date) return 0;
    if (piv.wday!=-1&&cur.wday!=piv.wday) return 0;
    return 1;
}
int checktime(info cur){
    if (piv.hh!=-1&&cur.hh!=piv.hh) return 0;
    if (piv.mm!=-1&&cur.mm!=piv.mm) return 0;
    if (piv.ss!=-1&&cur.ss!=piv.ss) return 0;
    return 1;
}
ll solve(ll val){
//    if (val<=btime) return btime;
//    cout<<val/daysec<<'\n';
    info cur=sectoinfo(val);
//    cout<<val<<"=>";
//    ENDL;
//    cur.print();
//    cout<<infotosecs(cur)<<'\n';
    if (checkdate(cur)&&checkwday(cur)){
//        cur.print();
        ll rem=daysec-infotosecs(cur)%daysec;
        REP(i,0,rem){
//            cur.print();
//piv.print();
            if (checktime(cur)) return infotosecs(cur);
            if (i<rem-1) cur=addsec(cur,1);
        }
    }
//    cur.print();
//    sectoinfo(0).print();
//    piv.print();
//    cout<<infotosecs(cur)<<'\n';
//    sectoinfo(infotosecs(cur)).print();
    cur=addsec(cur,daysec);
//    piv.print();
//    cur.print();
//    cout<<infotosecs(cur)<<'\n';
    cur.hh=best.hh;
    cur.mm=best.mm;
    cur.ss=best.ss;
//    cur.print();
//    best.print();
    while (!(checkdate(cur)&&checkwday(cur))) cur=addsec(cur,daysec);
//    cur.print();
    return infotosecs(cur);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    int test;
    scanf("%d",&test);
    while (test--){
        ll val;
        scanf("%lld",&val);
//        solve(val+1);
        printf("%lld\n",solve(val+1));
    }
}