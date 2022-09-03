use List::Util qw(min max sum);

use bigint;

my @cnt = split / /, <>;
@cnt = sort {$a <=> $b} @cnt;
$ans = int (($cnt[0] + $cnt[1] + (min ($cnt[2], 2 * ($cnt[0] + $cnt[1])))) / 3);
print $ans, "\n";