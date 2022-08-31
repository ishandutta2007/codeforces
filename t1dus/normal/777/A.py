n = int(input())
x = int(input())
n %= 6
pos = 0
for i in range(1,n+1):
    if i%2 == 1:
        if pos == 1:
            pos = 0
        elif pos == 0:
            pos = 1
    else:
        if pos == 2:
            pos = 1
        elif pos == 1:
            pos = 2
if pos == x:
    print(0)
else:
    pos = 1
    for i in range(1,n+1):
        if i%2 == 1:
            if pos == 1:
                pos = 0
            elif pos == 0:
                pos = 1
        else:
            if pos == 2:
                pos = 1
            elif pos == 1:
                pos = 2
    if pos == x:
        print(1)
    else:
        print(2)