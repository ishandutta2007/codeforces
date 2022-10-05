#include<bits/stdc++.h>

typedef long long ll;
const int N = 410;
inline bool leap(int year){return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;}

int years[N];
int month[N] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months[N];

struct Time{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    
    Time():year(0), month(0), day(0), hour(0), minute(0), second(0){}
    Time(int year, int month, int day, int hour, int minute, int second)
        :year(year), month(month), day(day), hour(hour), minute(minute), second(second){}

    int toDay(){
        ll ret = day - 1 + months[month - 1];
        ret += month >= 3 && leap(year);
        ret += (year - 1970) / 400 * years[400] + years[(year - 1970) % 400];
        return ret;
    }

    int toWeek(){
        int ret = (4 + toDay()) % 7;
        return ret ? ret : 7;
    }

    ll toSecond(){ 
        ll ret = 1ll * toDay() * 86400;
        ret += hour * 3600;
        ret += minute * 60 + second;
        return ret;
    }

    void addDay(){
        second = minute = hour = 0;
        ++ day;
        int limit = ::month[month] + (month == 2 && leap(year));
        if (day > limit){
            ++ month;
            day -= limit;
        }
        if (month > 12){
            month = 1;
            ++ year;
        }
    }

    void addSecond(){
        ++ second;
        if (second >= 60){
            second -= 60;
            ++ minute;
        }
        if (minute >= 60){
            minute -= 60;
            ++ hour;
        }
        if (hour >= 24){
            hour -= 24;
            addDay();
        }
    }
};

Time toTime(ll timeSecond){
    Time nowTime(1970, 1, 1, 0, 0, 0);
    int left = 1970, right = 100000;
    while (left < right){
        int mid = left + right + 1 >> 1;
        nowTime.year = mid;
        if (nowTime.toSecond() > timeSecond){
            right = mid - 1;
        }
        else{
            left = mid;
        }
    }
    nowTime.year = left;
    left = 1, right = 12;
    while (left < right){
        int mid = left + right + 1 >> 1;
        nowTime.month = mid;
        if (nowTime.toSecond() > timeSecond){
            right = mid - 1;
        }
        else{
            left = mid;
        }
    }
    nowTime.month = left;
    nowTime.day += (timeSecond - nowTime.toSecond()) / 86400;
    nowTime.hour = (timeSecond - nowTime.toSecond()) / 3600;
    nowTime.minute = (timeSecond - nowTime.toSecond()) / 60;
    nowTime.second = timeSecond - nowTime.toSecond();
    return nowTime;
}

int main(){
    //freopen("input.txt", "r", stdin);
    for (int i = 1970; i < 2370; ++ i){
        years[i - 1970 + 1] = years[i - 1970] + (365 + leap(i));
    }
    for (int i = 1; i <= 12; ++ i){
        months[i] = month[i] + months[i - 1];
    }
    int s, m, h, day, date, month;
    scanf("%d%d%d%d%d%d", &s, &m, &h, &day, &date, &month);
    int test;
    scanf("%d", &test);
    while (test --){
        ll second;
        scanf("%lld", &second);
        ++ second;
        Time nowTime = toTime(second);
        //printf("%d %d %d %d %d %d %d\n", nowTime.year, nowTime.month, nowTime.day, nowTime.hour, nowTime.minute, nowTime.second, nowTime.toWeek());
        while (~h && h != nowTime.hour ||
                ~m && m != nowTime.minute ||
                ~s && s != nowTime.second){
            nowTime.addSecond();
        }
        while (~month && nowTime.month != month ||
                ~day && ~date && nowTime.toWeek() != day && nowTime.day != date || 
                ~day && !~date && nowTime.toWeek() != day || ~date && !~day && nowTime.day != date){
            nowTime.addDay();
        }
        while (~h && h != nowTime.hour ||
                ~m && m != nowTime.minute ||
                ~s && s != nowTime.second){
            nowTime.addSecond();
        }
        //printf("%d %d %d %d %d %d %d\n", nowTime.year, nowTime.month, nowTime.day, nowTime.hour, nowTime.minute, nowTime.second, nowTime.toWeek());
        printf("%lld\n", nowTime.toSecond());
    }
    return 0;
}