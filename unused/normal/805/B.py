from sys import stdout
n = input()
for i in xrange(n):
    stdout.write(chr(97 + (i / 2) % 2))