n = int(input())
a = list(map(int, input().split()))
cnt = 1; maxcnt = 1;
for i in range(1,len(a)):
    cnt = cnt+1 if a[i]>=a[i-1] else 1
    maxcnt = max(maxcnt, cnt)
print(maxcnt)