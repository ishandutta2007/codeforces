n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
cnt = 0
for i in range(n):
    if a[i] != b[i]:
        cnt += 1 
        
if cnt == 1:
    done = list(range(1,n+1))
    x = 0
    for i in range(n):
        if a[i] == b[i]:
            try:
                done.remove(a[i])
            except:
                pass
        else:
            x = i
            try:
                done.remove(a[i])
            except:
                pass
            try:
                done.remove(b[i])
            except:
                pass
    arr = a[::]
    arr[x] = done[0]
    for i in arr:
        print(i,end = ' ')
        
else:
    arr = a[::]
    x = -1
    y = -1
    for i in range(n):
        if a[i] == b[i]:
            pass
        else:
            if x == -1:
                x = i
            else:
                y = i
    br = arr[::]
    arr[x] = b[x]
    br[y] = b[y]
    if len(set(br)) == n:
        arr = br[::]
    for i in arr:
        print(i,end = ' ')