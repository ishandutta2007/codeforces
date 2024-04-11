#use strict;
use warnings;

$n=<STDIN>;
if($n%2==1) {
    print "7";
}
print "1"x(($n-$n%2*3)/2);