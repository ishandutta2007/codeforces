from math import sqrt

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
s = input()
a = ["Danil","Olya","Slava","Ann","Nikita"]
cnt = 0
for i in a:
    cnt += s.count(i)
if cnt== 1: print("YES")        
else: print("NO")