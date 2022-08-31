def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = list_input()
if a[0]%2 and a[-1]%2 and n%2:
  print("Yes")
else: print("No")