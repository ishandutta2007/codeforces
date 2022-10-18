import random

n = int(input())

a = list(map(int, input().split()))
a.insert(0, 0)

cnt = [0] * (n + 1)
cnt2 = [0] * (n + 1)
hashs = [0] * (n + 1)

r1 = [None] * (n + 1)
r2 = [None] * (n + 1)

for i in range(1, n + 1):
    r1[i] = random.randint(1, 1000000000000)
    r2[i] = random.randint(1, 1000000000000)

mpp = {
    0: 1
}

sum = 0
l = 1

ans = 0

for i in range(1, n + 1):
    if cnt[a[i]] == 1:
        sum -= r1[a[i]]
    elif cnt[a[i]] == 2:
        sum -= r2[a[i]]
        
    cnt[a[i]] += 1
    
    if cnt[a[i]] == 1:
        sum += r1[a[i]]
    elif cnt[a[i]] == 2:
        sum += r2[a[i]]
    else:
        cnt[a[i]] = 0
    
    cnt2[a[i]] += 1
    
    while cnt2[a[i]] == 4:
        mpp[hashs[l - 1]] = mpp[hashs[l - 1]] - 1
        cnt2[a[l]] -= 1
        l += 1
    
    hashs[i] = sum
    
    tans = 0
    
    if sum in mpp:
        tans += mpp[sum]
        mpp[sum] = mpp[sum] + 1
    
    else:
        mpp[sum] = 1
    
    ans += tans

print(ans)