{$r-,q-,s-,i-,o+}
var
  max,ax,ay,ll,rr,i,j:longint;
  kol,f:array[0..500500]of longint;
  s:ansistring;

begin
  readln(s);
  kol[0]:=0;
  for i:=1 to length(s)do kol[i]:=kol[i-1]+ord(s[i]='[');
  max:=-1;
  for i:=length(s)downto 1 do begin
    f[i]:=0;
    if (s[i]=']')then continue;
    if (s[i]=')')then continue;
    j:=i+f[i+1]+1;
    if ((s[i]='(')and(s[j]=')'))or
        ((s[i]='[')and(s[j]=']'))then begin
          f[i]:=f[i+1]+2;
          j:=i+f[i];
          if (j<=length(s))then inc(f[i],f[j])
        end;
    if (f[i]=0)then continue;
    ll:=i;rr:=i+f[i]-1;
    if (kol[rr]-kol[ll-1]>max)then begin
      max:=kol[rr]-kol[ll-1];
      ax:=ll;ay:=rr;
    end;
  end;
  if (max<0)then begin writeln(0);exit; end;
  writeln(max);
  writeln(copy(s,ax,ay-ax+1));
end.