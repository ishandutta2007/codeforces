n = input()
s = raw_input()

if s.count('0') == s.count('1'):
    print(2)
    print(s[0] + ' ' + s[1:])
else:
    print(1)
    print(s)