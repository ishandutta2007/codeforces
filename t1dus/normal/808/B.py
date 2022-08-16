n,k = map(int,input().split())
a = list(map(int,input().split()))
pref = [0]
for i in a:
    pref.append(i+pref[-1])
cnt = 0
cur = 0
for i in range(k,n+1):
    cnt += 1
    cur += pref[i]-pref[i-k]
print(cur/cnt)