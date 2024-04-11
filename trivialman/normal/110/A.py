n = input()
num = len([i for i in n if i in ['4','7']])
print('YES' if num in [4,7] else 'NO')