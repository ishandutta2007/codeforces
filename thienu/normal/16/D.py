n = int(input())
cur_time = 0
ans = 1
rep = 0
for i in range(n):
    s = input()
    hour = int(s[1:3])
    if hour == 12:
        hour = 0
    min = int(s[4:6])
    is_pm = s[7] == "p"
    time = hour * 60 + min + (1 if is_pm else 0) * 12 * 60
    # print(hour, min, is_pm, time)
    if time == cur_time:
        if rep == 10:
            ans += 1
            rep = 1
        else:
            rep += 1
    elif time > cur_time:
        cur_time = time
        rep = 1
    else:
        ans += 1
        rep = 1
        cur_time = time
print(ans)