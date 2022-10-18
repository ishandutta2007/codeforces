n = int(input());
s = input();
cnt = 1;
ans = "";
for i in range(1, n+1):
    # print(s[i] + " " + s[i-1]);
    # print(s[i] != s[i-1]);
    # print(cnt);
    if i == n or s[i] != s[i-1]:
        if s[i-1] == 'e' or s[i-1] == 'o':
            if (cnt > 2):
                cnt = 1;
        elif s[i-1] == 'a' or s[i-1] == 'i' or s[i-1] == 'u' or s[i-1] == 'y':
            cnt = 1;
        for j in range(cnt):
            ans += s[i-1];
        cnt = 0;
    cnt += 1;
        
print(ans);