const
  INF=1000000000;
  km:array[1..12]of longint=(31,29,31,30,31,30,31,31,30,31,30,31);

var
  s,p:ansistring;
  i,mm,hh,dd,mt,ss,ms,kt,n,m,j:longint;
  t:array[0..1000000]of longint;
  tm:array[0..12]of longint;

  function pars(mm,dd,hh,mt,ss:longint):longint;
    begin
      pars:=(tm[mm-1]+dd-1)*24*60*60+hh*60*60+mt*60+ss;
    end;

begin
//  assign(input,'input.txt');reset(input);
  readln(n,m);
  j:=0;t[0]:=-INF;kt:=0;
  tm[0]:=0;
  for i:=1 to 12 do tm[i]:=tm[i-1]+km[i];
  while (not eof)do begin
    readln(s);
    p:=copy(s,1,19);
    delete(s,1,5);

    val(copy(s,1,2),mm);
    delete(s,1,3);

    val(copy(s,1,2),dd);
    delete(s,1,3);

    val(copy(s,1,2),hh);
    delete(s,1,3);

    val(copy(s,1,2),mt);
    delete(s,1,3);

    val(copy(s,1,2),ss);
    s:='';

    ms:=pars(mm,dd,hh,mt,ss);

    inc(kt);
    t[kt]:=ms;
    while (t[kt]-t[j]+1>n)do inc(j);
    if (kt-j+1>=m)then begin
      writeln(p);
      halt(0);
    end;
  end;
  writeln(-1);
end.