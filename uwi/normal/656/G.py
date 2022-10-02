f,i,t = map(int,input().split())
a = [0] * i
for z in range(f):
    u = input().strip()
    for q in range(i):
        if u[q] == 'Y': a[q] += 1
print(len([_ for _ in a if _ >= t]))
# kitten
# meow~~