{$r-,q-,s-,i-,o+}
type
  TNum=array[0..5]of int64;

const
  eps=1e-9;
  mbase:int64=1000000000000000000;
  mk=18;

var
  ts:ansistring;
  tp,t1:TNum;
  ft:boolean;
  fq:extended;
  a,b:array[0..500500]of int64;
  kst,n,i,ll,rr,mid:longint;
  s1,f:array[0..100500]of TNum;
  s2:array[0..500500]of int64;
  sx:array[0..500500]of extended;

  function lsum(a,b:TNum):Tnum;
    var
      i:longint;
    begin
      while (a[0]<b[0])do begin
        inc(a[0]);
        a[a[0]]:=0;
      end;
      while (b[0]<a[0])do begin
        inc(b[0]);
        b[b[0]]:=0;
      end;
      a[a[0]+1]:=0;
      for i:=1 to a[0] do begin
        a[i]:=a[i]+b[i];
        while (a[i]>=mbase)do begin
          a[i]:=a[i]-mbase;
          a[i+1]:=a[i+1]+mbase;
        end;
      end;
      if (a[a[0]+1]>0)then inc(a[0]);
      lsum:=a;
    end;

  function lminus(a,b:TNum):Tnum;
    var
      i:longint;

    begin
      while (b[0]<a[0])do begin
        inc(b[0]);
        b[b[0]]:=0;
      end;
      for i:=1 to a[0] do begin
        a[i]:=a[i]-b[i];
        while (a[i]<0)do begin
          a[i]:=a[i]+mbase;
          a[i+1]:=a[i+1]-mbase;
        end;
      end;
      lminus:=a;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  kst:=1;
  sx[kst]:=0;
  s1[kst][0]:=1;
  s1[kst][1]:=0;
  s2[kst]:=b[1];

  f[1][0]:=1;
  f[1][1]:=0;
  for i:=2 to n do begin
    ll:=0;rr:=kst+1;
    while (ll<rr-1)do begin
      mid:=(ll+rr)shr 1;
      if (a[i]+eps>=sx[mid])
        then ll:=mid
        else rr:=mid;
    end;
    rr:=ll;
    tp[0]:=1;
    tp[1]:=int64(s2[rr])*a[i];
    if (tp[1]=mbase)then begin
      inc(tp[0]);
      tp[2]:=1;
      tp[1]:=0;
    end;
    f[i]:=lsum(s1[rr],tp);
    while (kst>0)do begin
      t1:=lminus(f[i],s1[kst]);
      if (t1[0]=1)
        then ft:=(t1[1]+eps>=int64(s2[kst]-b[i])*sx[kst])
        else ft:=true;
      if (ft)then break;
      dec(kst);
    end;
    tp:=lminus(f[i],s1[kst]);
    fq:=s2[kst]-b[i];
    inc(kst);
    s1[kst]:=f[i];
    s2[kst]:=b[i];
    if (tp[0]=1)then sx[kst]:=tp[1]/fq else sx[kst]:=(tp[1]/fq)+(tp[2]/fq)*1e18;
  end;
  write(f[n][f[n][0]]);
  for i:=f[n][0]-1 downto 1 do begin
    str(f[n][i],ts);
    while (length(tS)<mk)do ts:='0'+ts;
    write(ts);
  end;
  writeln;
  close(output);close(input);
end.