def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k = map_input()
if (n//k)%2==1:
    print("YES")
else:
    print("NO")