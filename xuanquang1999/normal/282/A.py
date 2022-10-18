var = 0
n = int(input())
for i in range(0, n):
    s = input()
    if s in ['X++', '++X']:
        var = var + 1
    else:
        var = var - 1
print(str(var))