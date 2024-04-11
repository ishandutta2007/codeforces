n = int(input())
a = []
for i in range (n):
    a.append(list(input()))
ans = 0
for i in range (n):
    tmp = 1
    for j in range(i+1,n):
        if (a[i] == a[j]):
            tmp += 1
    ans = max(ans,tmp)
print(ans)