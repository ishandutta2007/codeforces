from collections import defaultdict

N = int(input())
A = list(map(int, input().split()))

ans = []
cnt = 0
num = 0
dic = defaultdict(int)
seen = defaultdict(int)
for a in A:
    if a > 0:
        if dic[a] == 0:
            if not seen[a]:
                dic[a] = 1
                cnt += 1
                num += 1
                seen[a] = 1
        else:
            print(-1)
            exit()
    else:
        a *= -1
        if seen[a] and dic[a]:
            dic[a] = 0
            cnt += 1
            num -= 1
        else:
            print(-1)
            exit()
    if num == 0:
        ans.append(cnt)
        cnt = 0
        seen = defaultdict(int)

if num == 0:
    print(len(ans))
    print(*ans)
else:
    print(-1)