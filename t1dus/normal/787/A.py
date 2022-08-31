a,b = map(int,input().split())
c,d = map(int,input().split())

valid = [0]*(1000001)

cnt = b

while cnt <= 1000000:
    valid[cnt] += 1
    cnt += a

cnt = d

while cnt <= 1000000:
    valid[cnt] += 1
    cnt += c

for i in range(1000001):
    if valid[i] == 2:
        print(i)
        break
else:
    print(-1)