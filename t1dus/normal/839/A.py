def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k = map_input()
a = list_input()
cur = 0
cnt = 1
for i in a:
  cur += i
  if cur >= 8:
    cur -= 8
    k -= 8
  else:
    k -= cur
    cur = 0
  if k <= 0:
    break
  cnt += 1
if k <= 0:
  print(cnt)
else:
  print(-1)