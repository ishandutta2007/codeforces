_ = raw_input()
s = raw_input()
for i in xrange(50, 0, -1):
    s = s.replace('o'+'go'*i, '***')
print s