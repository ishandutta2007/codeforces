def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = list_input()
cur = 0
ans = 0
for i in range(n):
  if a[i] == 0:
    cur += 1
    ans = max(ans,cur+a[i+1:].count(1))
print(max(ans,a.count(1)))