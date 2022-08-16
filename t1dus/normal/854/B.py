def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()

n,k = map_input()
a = -1
b = -1
if k == 0 or k == n:
  a = 0
  b = 0
else:
  a = 1
  b = n-k
  b = min(b,k*2)
print(a,b)