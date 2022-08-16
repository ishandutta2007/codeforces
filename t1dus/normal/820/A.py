def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
c,v0,v1,a,l = map_input()
cur = 0
cnt = 0
while cur < c:
    if cnt != 0:
        cur += min(v1,v0+cnt*a)-l
    else:
        cur += min(v1,v0+cnt*a)
    cnt += 1
print(cnt)