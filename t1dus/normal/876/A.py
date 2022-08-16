'''input
1
2
3
5
'''
n = int(input())
a = int(input())
b = int(input())
c = int(input())
cur = 0
pos = 0
for i in range(n-1):
    if pos == 0:
        if a < b:
            pos = 1
            cur += a
        else:
            pos = 2
            cur += b 
    elif pos == 1:
        if a < c: 
            pos = 1
            cur += a
        else:
            pos = 3
            cur += c
    else:
        if b < c: 
            pos = 2
            cur += b
        else:
            pos = 3
            cur += c                     
print(cur)