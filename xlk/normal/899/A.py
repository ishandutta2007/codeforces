input()
s = raw_input()
a = s.count('1')
b = s.count('2')
print [b + (a - b) / 3, a][a < b]