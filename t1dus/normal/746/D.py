n,k,a,b = map(int,input().split())
order = []
if a == b:
    print('GB'*a)
elif a > b:
    val = 0
    for i in range(n):
        if a > b and val < k:
            a -= 1
            val += 1
            order.append('G')
        else:
            b -= 1
            val = 0
            order.append('B')
    if a == b:
        print(''.join(order))
    else:
        print('NO')
else:
    a,b = b,a
    val = 0
    for i in range(n):
        if a > b and val < k:
            a -= 1
            val += 1
            order.append('G')
        else:
            b -= 1
            val = 0
            order.append('B')
    if a == b:
        for i in order:
            if i == 'B':
                print('G',end='')
            else:
                print('B',end='')    
        print('')    
    else:
        print('NO')