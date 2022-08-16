"""input
2
abcDCE
htQw27
"""
def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()

l,r = map_input()
print("YES")
for i in range(l,r,2): print(i,i+1)