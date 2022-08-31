def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
s = set([])
for _ in range(n):
  x = input()
  if x in s:
    print("YES")
  else:
    print("NO")
  s.add(x)