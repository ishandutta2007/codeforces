a = '31 28 31 30 31 30 31 31 30 31 30 31 '
b = '31 29 31 30 31 30 31 31 30 31 30 31 '
input()
print ['No', 'Yes'][raw_input() in a + a + a + b + a + a]