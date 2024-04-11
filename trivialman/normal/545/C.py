import sys
try: fin = open('test.in','r').readline
except: fin = sys.stdin.readline

n = int(fin())
a = [tuple(map(int, fin().split())) for i in range(n)]
a.append((3e9,0))

pos = -1e9
ans = 0
for i in range(n):
    if (a[i][0] - a[i][1] > pos) :
        pos = a[i][0]
        ans += 1
    elif (a[i][0] + a[i][1] < a[i+1][0]):
        pos = a[i][0] + a[i][1]
        ans += 1
    else:
        pos = a[i][0]
print(ans)