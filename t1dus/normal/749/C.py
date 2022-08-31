from collections import deque
n = int(input())
s = input()
d = deque()
r = deque()
for i in range(n):
    if s[i] == 'D':
        d.append(i)
    else:
        r.append(i)
while True:
    # print('D',d)
    # print('R',r)
    
    if not d:
        print('R')
        break
    if not r:
        print('D')
        break    
    if d[0] < r[0]:
        r.popleft()
        d.append(d.popleft()+n)
    else:
        d.popleft()
        r.append(r.popleft()+n)