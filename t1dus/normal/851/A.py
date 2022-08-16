def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k,t = map_input()
if t <= k:
  print(t)
elif t <= n:
  print(k)
else:
  print(k+n-t)