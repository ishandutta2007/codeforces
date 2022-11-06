s = input()
v = ['a', 'e', 'i', 'o', 'u', 'y']
f = lambda c: c if ord(c) >= ord('a') and ord(c) <= ord('z') else chr(ord('a') + ord(c) - ord('A'))
print(''.join(['' if f(s[i]) in v else '.' + f(s[i]) for i in range(len(s))]))