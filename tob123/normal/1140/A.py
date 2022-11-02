n = int(input())
a = [int(x) for x in input().split()]

to = 0
cnt = 1
for i in range(n):
    if i > to:
        cnt += 1
    to = max(to, a[i]-1)
    
print(cnt)