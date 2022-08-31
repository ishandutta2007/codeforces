s,k = input().split()
k = int(k)
n = len(s)
ans = 0
cnt = 0
for i in range(n-1,-1,-1):
    if cnt == k:
        print(ans)
        break
    elif s[i] == '0':
        cnt += 1
    else:
        ans += 1
else:
    print(n-1)