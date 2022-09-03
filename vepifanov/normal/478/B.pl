use bigint;

my $n, $m;
($n, $m) = split / /, <>;
my $kmax = ($n - $m + 1) * ($n - $m) / 2;
my $team = int ($n / $m);
my $big = $n - $team * $m;
my $small = $m - $big;
my $kmin = $small * $team * ($team - 1) / 2 + $big * $team * ($team + 1) / 2;
print $kmin, " ", $kmax, "\n";