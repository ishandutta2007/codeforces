s = input()
for c in s:
    c = c.lower()
    if c not in 'aoyeui':
        print('.' + c, end = '')