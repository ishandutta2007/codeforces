def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k,m = map_input()
a = list_input()
a.sort()
sm = sum(a)
ans = 0
for i in range(n+1):
  if sm*i > m:
    break
  m1 = m-sm*i
  cnt = [n-i]*(k)
  cur = 0
  res = (k+1)*i
  while m1 > 0:
    if cur >= k or a[cur] > m1: break
    x = min(m1//a[cur],cnt[cur])
    res += x
    m1 -= x*a[cur]
    cur += 1
  ans = max(res,ans)
print(ans)