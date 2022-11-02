n, x = map(int, input().split())
high = 999999
arr = []
num = (n - 1) - (n - 1) % 4
for i in range(num):
    arr.append(high - i)
n -= num
if n == 1:
    arr.append(x)
if n == 2 and len(arr) == 0:
    arr.append(0)
    arr.append(x)
if n == 2 and len(arr) > 2:
    arr = arr[:-4]
    arr.append(x^1)
    arr.append(x^2)
    arr.append(x^3)
    arr.append(131072)
    arr.append(131072 + 262144)
    arr.append(262144)
if n == 3:
    arr.append(x + 131072)
    arr.append(131072 + 262144)
    arr.append(262144)
if n == 4:
    arr.append(x + 131072)
    arr.append(131072 + 262144)
    arr.append(262144 + 524288)
    arr.append(524288)

if len(arr) == 2 and x == 0:
    print('NO')
else:
    print('YES')
    print(' '.join(map(str,arr)))