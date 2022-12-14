// benchmark test. Probably slower (with some local benchmark)

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// { ==== Begin library FastIO.h ====
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
namespace io{using namespace std;template<class T>struct is_iterator{template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*declval<U>(),bool()){return true;}template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);};using uint=unsigned int;const uint BUFFER_SIZE=1<<12;const uint MAX_LENGTH=1<<7;namespace Detail{struct Width{uint value;};struct Fill{char value;};struct Base{uint value;};struct Precision{uint value;};struct Delimiter{const char*value;};}Detail::Width setWidth(uint value=0){return{value};}Detail::Fill setFill(char value=' '){return{value};}Detail::Base setBase(uint value=10){assert(2<=value&&value<=36);return{value};}Detail::Precision setPrecision(uint value=9){assert(value<MAX_LENGTH);return{value};}Detail::Delimiter setDelimiter(const char*value=" "){return{value};}class InputDevice{protected:const char*head;const char*tail;InputDevice(const char*head,const char*tail): head(head),tail(tail),base(setBase().value){}virtual void fillInput()=0;inline char nextChar(){if(__builtin_expect(head>=tail,false))fillInput();return*head++;}template<class I>int readUnsignedIntGeneral(I&arg,char c){I value=0;int length=0;for(;;++length,c=nextChar()){if(isDigit(c))c-='0';else if(isUpper(c))c-='A'-10;else if(isLower(c))c-='a'-10;else c=base;if(c>=base)break;value=base*value+c;}arg=value;return--head,length;}template<class I>inline int readUnsignedInt(I&arg,char c){if(__builtin_expect(base>10,false))return readUnsignedIntGeneral(arg,c);I value=0;int length=0;for(;static_cast<unsigned char>(c-'0')<base;++length,c=nextChar())value=base*value+c-'0';arg=value;return--head,length;}template<class I>inline bool readSignedInt(I&arg,char c){bool negative=c=='-';if(negative)c=nextChar();typename make_unsigned<I>::type unsignedArg;if(readUnsignedInt(unsignedArg,c)==0)return false;arg=negative ? ~static_cast<I>(unsignedArg-1): static_cast<I>(unsignedArg);return true;}template<class F>bool readFloatingPoint(F&arg,char c){bool negative=c=='-';if(negative)c=nextChar();unsigned long long integerPart;if(readUnsignedInt(integerPart,c)==0)return false;arg=static_cast<F>(integerPart);if(nextChar()=='.'){unsigned long long fractionalPart=0;int fractionalLength=readUnsignedInt(fractionalPart,nextChar());if(fractionalLength>0){unsigned long long basePower=1;for(;fractionalLength;--fractionalLength)basePower*=base;arg+=static_cast<F>(fractionalPart)/basePower;}}else --head;if(negative)arg=-arg;return true;}public:uint base;InputDevice(InputDevice const&)=delete;InputDevice&operator=(InputDevice const&)=delete;static inline bool isSpace(char c){return static_cast<unsigned char>(c-'\t')<5||c==' ';}static inline bool isDigit(char c){return static_cast<unsigned char>(c-'0')<10;}static inline bool isUpper(char c){return static_cast<unsigned char>(c-'A')<26;}static inline bool isLower(char c){return static_cast<unsigned char>(c-'a')<26;}static inline bool isOneOf(char c,const char*str){return strchr(str,c)!=nullptr;}void putBack(){--head;}inline bool readChar(char&arg){if(__builtin_expect(head>=tail,false)){fillInput();if(__builtin_expect(head>=tail,false))return arg='\0',false;}return arg=*head++,true;}template<class UnaryPredicate>inline char skipCharacters(UnaryPredicate isSkipped){char c;do{c=nextChar();}while(isSkipped(c));return c;}inline char skipCharacters(){return skipCharacters(isSpace);}template<class UnaryPredicate>inline int readString(char*arg,int limit,UnaryPredicate isTerminator){skipCharacters(isTerminator);int charsRead=0;for(--head,--limit;head<tail;fillInput()){ptrdiff_t chunkSize=find_if(head,min(tail,head+limit-charsRead),isTerminator)-head;arg=copy_n(head,chunkSize,arg);head+=chunkSize;charsRead+=chunkSize;if(chunkSize==0||head<tail)break;}return*arg='\0',charsRead;}inline int readString(char*arg,int limit,const char*terminators){if(!*terminators)return readString(arg,limit,InputDevice::isSpace);return readString(arg,limit,[terminators](char c){return InputDevice::isOneOf(c,terminators);});}inline bool read(Detail::Base newBase){base=newBase.value;return true;}inline bool read(){return true;}inline bool read(char&arg){return readChar(arg);}template<class I>inline typename enable_if<is_integral<I>::value&&is_unsigned<I>::value,bool>::type read(I&arg){return readUnsignedInt(arg,skipCharacters())>0;}template<class I>inline typename enable_if<is_integral<I>::value&&is_signed<I>::value,bool>::type read(I&arg){return readSignedInt(arg,skipCharacters());}template<class F>inline typename enable_if<is_floating_point<F>::value,bool>::type read(F&arg){return readFloatingPoint(arg,skipCharacters());}inline bool read(const char&arg){skipCharacters([arg](char c){return arg!=c;});return true;}inline bool read(const char*arg){if(*arg)skipCharacters([arg](char c){return InputDevice::isOneOf(c,arg);});else skipCharacters();return putBack(),true;}inline bool read(bool(*isSkipped)(char)){skipCharacters(isSkipped);putBack();return true;}template<class I,class Terminator,class... Ts>inline typename enable_if<is_integral<I>::value,bool>::type read(char*arg,I limit,Terminator terminator,Ts&&... args){readString(arg,static_cast<int>(limit),terminator);return read(forward<Ts>(args)...);}template<class I>inline typename enable_if<is_integral<I>::value,bool>::type read(char*arg,I limit){return read(arg,limit,"");}template<class... Ts>inline bool read(char*first,char*last,Ts&&... args){return read(first,static_cast<int>(last-first),forward<Ts>(args)...);}template<int N,class... Ts>inline bool read(char(&arg)[N],Ts&&... args){return read(static_cast<char*>(arg),N,forward<Ts>(args)...);}template<class Terminator,class... Ts>inline bool read(string&arg,Terminator terminator,Ts&&... args){for(int length=16,last=0;;last+=length,length<<=1){arg.resize(last+length);int charsRead=readString(&arg[last],length+1,terminator);if(charsRead<length){arg.resize(last+charsRead);return read(forward<Ts>(args)...);}}}inline bool read(string&arg){return read(arg,"");}template<class T1,class T2>inline bool read(pair<T1,T2>&arg){return read(arg.first,arg.second);}template<class T>inline bool read(complex<T>&arg){T real,imag;if(!read(real,imag))return false;arg.real(real),arg.imag(imag);return true;}template<class T>inline bool read(vector<T>&arg){uint n;if(!read(n))return false;arg.resize(n);return read(arg.begin(),arg.end());}template<class Iterator,class... Ts>inline typename enable_if<is_iterator<Iterator>::value,bool>::type read(Iterator first,Iterator last,Ts&&... args){for(;first!=last;++first)if(!read(*first))return false;return read(forward<Ts>(args)...);}template<class Iterator,class I,class... Ts>inline typename enable_if<is_iterator<Iterator>::value&&is_integral<I>::value,bool>::type read(Iterator first,I count,Ts&&... args){return read(first,first+count,forward<Ts>(args)...);}template<class T>inline auto read(T&arg)->decltype(arg.read(*this)){return arg.read(*this);}template<class T0,class T1,class... Ts>inline typename enable_if<!is_iterator<T0>::value&&!is_convertible<T0,char*>::value,bool>::type read(T0&&arg0,T1&&arg1,Ts&&... args){return read(forward<T0>(arg0))&&read(forward<T1>(arg1),forward<Ts>(args)...);}};class InputFile : public InputDevice{FILE*file;bool lineBuffered;bool owner;char buffer[BUFFER_SIZE];void fillInput()override{head=buffer;*buffer='\0';if(__builtin_expect(!lineBuffered,true)){tail=head+fread(buffer,1,BUFFER_SIZE,file);}else{tail=head;if(fgets(buffer,BUFFER_SIZE,file))while(*tail)++tail;}}public:InputFile(FILE*file=stdin,bool lineBuffered=true,bool takeOwnership=false): InputDevice(buffer,buffer),file(file),lineBuffered(lineBuffered),owner(takeOwnership){}InputFile(const char*fileName): InputFile(fopen(fileName,"r"),false,true){}~InputFile(){if(owner)fclose(file);}};class InputString : public InputDevice{void fillInput()override{while(*tail)++tail;}public:InputString(const string&s): InputDevice(s.data(),s.data()+s.size()){}InputString(const char*s): InputDevice(s,s+strlen(s)){}};class OutputDevice{protected:char buffer[BUFFER_SIZE+MAX_LENGTH];char*output;char*end;bool separate;OutputDevice(): output(buffer),end(buffer+BUFFER_SIZE+MAX_LENGTH),separate(false),width(setWidth().value),fill(setFill().value),base(setBase().value),precision(setPrecision().value),delimiter(setDelimiter().value){computeBasePower();}virtual void writeToDevice(uint count)=0;inline void flushMaybe(){if(__builtin_expect(output>=buffer+BUFFER_SIZE,false)){writeToDevice(BUFFER_SIZE);output=copy(buffer+BUFFER_SIZE,output,buffer);}}void computeBasePower(){basePower=1;for(uint i=0;i<precision;++i)basePower*=base;}template<class I>inline char*writeUnsignedInt(I arg,char*last){if(__builtin_expect(arg==0,false))*--last='0';if(__builtin_expect(base==10,true)){for(;arg;arg/=10)*--last='0'+arg%10;}else for(;arg;arg/=base){I digit=arg%base;*--last=digit<10 ? '0'+digit : 'A'-10+digit;}return last;}template<class I>inline char*writeSignedInt(I arg,char*last){auto unsignedArg=static_cast<typename make_unsigned<I>::type>(arg);if(arg<0){last=writeUnsignedInt(~unsignedArg+1,last);*--last='-';return last;}return writeUnsignedInt(unsignedArg,last);}template<class F>char*writeFloatingPoint(F arg,char*last){bool negative=signbit(arg);if(negative)arg=-arg;if(isnan(arg))for(int i=0;i<3;++i)*--last=i["NaN"];else if(isinf(arg))for(int i=0;i<3;++i)*--last=i["fnI"];else{auto integerPart=static_cast<unsigned long long>(arg);auto fractionalPart=static_cast<unsigned long long>((arg-integerPart)*basePower+F(0.5));if(fractionalPart>=basePower)++integerPart,fractionalPart=0;char*point=last-precision;if(precision>0){io::fill(point,writeUnsignedInt(fractionalPart,last),'0');*--point='.';}last=writeUnsignedInt(integerPart,point);}if(negative)*--last='-';return last;}inline int writeT(char*first){int delimiterLenght=separate ? writeDelimiter(): 0;separate=true;uint charsWritten=static_cast<uint>(end-first);if(__builtin_expect(charsWritten<width,false))charsWritten+=writeFill(width-charsWritten);output=copy(first,end,output);flushMaybe();return delimiterLenght+static_cast<int>(charsWritten);}inline int writeFill(uint count){int charsWritten=static_cast<int>(count);if(__builtin_expect(output+count+MAX_LENGTH<end,true)){if(count==1)*output++=fill;else output=fill_n(output,count,fill);}else for(uint chunkSize=static_cast<uint>(buffer+BUFFER_SIZE-output);;chunkSize=BUFFER_SIZE){if(chunkSize>count)chunkSize=count;output=fill_n(output,chunkSize,fill);flushMaybe();if((count-=chunkSize)==0)break;}return charsWritten;}public:uint width;char fill;uint base;uint precision;unsigned long long basePower;string delimiter;OutputDevice(OutputDevice const&)=delete;OutputDevice&operator=(OutputDevice const&)=delete;virtual ~OutputDevice(){};inline int writeChar(char arg){separate=false;*output++=arg;flushMaybe();return 1;}inline int writeString(const char*arg,size_t length,bool checkWidth=true){separate=false;uint count=static_cast<uint>(length);int charsWritten=static_cast<int>(count)+(checkWidth&&count<width ? writeFill(width-count): 0);if(__builtin_expect(output+count+MAX_LENGTH<end,true)){if(count==1)*output++=*arg;else output=copy_n(arg,count,output);}else for(uint chunkSize=static_cast<uint>(buffer+BUFFER_SIZE-output);;chunkSize=BUFFER_SIZE){if(chunkSize>count)chunkSize=count;output=copy_n(arg,chunkSize,output);flushMaybe();if((count-=chunkSize)==0)break;arg+=chunkSize;}return charsWritten;}inline int writeDelimiter(){return writeString(delimiter.c_str(),delimiter.size(),false);}inline void flush(){writeToDevice(static_cast<uint>(output-buffer));output=buffer;}inline int write(Detail::Width newWidth){width=newWidth.value;return 0;}inline int write(Detail::Fill newFill){fill=newFill.value;return 0;}inline int write(Detail::Base newBase){base=newBase.value;computeBasePower();return 0;}inline int write(Detail::Precision newPrecision){precision=newPrecision.value;computeBasePower();return 0;}inline int write(Detail::Delimiter newDelimiter){delimiter=newDelimiter.value;return 0;}inline int write(){return 0;}inline int write(char arg){return writeChar(arg);}template<class I>inline typename enable_if<is_integral<I>::value&&is_unsigned<I>::value,int>::type write(I arg){return writeT(writeUnsignedInt(arg,end));}template<class I>inline typename enable_if<is_integral<I>::value&&is_signed<I>::value,int>::type write(I arg){return writeT(writeSignedInt(arg,end));}template<class F>inline typename enable_if<is_floating_point<F>::value,int>::type write(F arg){return writeT(writeFloatingPoint(arg,end));}inline int write(const char*arg){return writeString(arg,strlen(arg));}template<int N>inline int write(char(&arg)[N]){return writeString(arg,strlen(arg));}inline int write(const string&arg){return writeString(arg.c_str(),arg.size());}template<class T1,class T2>inline int write(const pair<T1,T2>&arg){int charsWritten=write(arg.first);charsWritten+=writeDelimiter();return charsWritten+write(arg.second);}template<class T>inline int write(const complex<T>&arg){return write(real(arg),imag(arg));}template<class Iterator,class... Ts>inline typename enable_if<is_iterator<Iterator>::value,int>::type write(Iterator first,Iterator last,Ts&&... args){int charsWritten=0;for(;first!=last;charsWritten+=++first==last ? 0 : writeDelimiter())charsWritten+=write(*first);return charsWritten+write(forward<Ts>(args)...);}template<class Iterator,class I,class... Ts>inline typename enable_if<is_iterator<Iterator>::value&&is_integral<I>::value,int>::type write(Iterator first,I count,Ts&&... args){return write(first,first+count,forward<Ts>(args)...);}template<class T>inline auto write(const T&arg)->decltype(arg.write(*this)){return arg.write(*this);}template<class T0,class T1,class... Ts>inline typename enable_if<!is_iterator<T0>::value,int>::type write(T0&&arg0,T1&&arg1,Ts&&... args){int charsWritten=write(forward<T0>(arg0));return charsWritten+write(forward<T1>(arg1),forward<Ts>(args)...);}};class OutputFile : public OutputDevice{FILE*file;bool owner;void writeToDevice(uint count)override{fwrite(buffer,1,count,file);fflush(file);}public:OutputFile(FILE*file=stdout,bool takeOwnership=false): file(file),owner(takeOwnership){}OutputFile(const char*fileName): OutputFile(fopen(fileName,"w"),true){}~OutputFile()override{flush();if(owner)fclose(file);}};class OutputString : public OutputDevice{string&str;void writeToDevice(uint count)override{str.append(buffer,count);}public:OutputString(string&str): OutputDevice(),str(str){}~OutputString()override{flush();}};unique_ptr<InputDevice>input;unique_ptr<OutputDevice>output;template<class... Ts>inline bool read(Ts&&... args){return input->read(forward<Ts>(args)...);}template<class... Ts>inline int write(Ts&&... args){return output->write(forward<Ts>(args)...);}template<class... Ts>inline int writeln(Ts&&... args){return write(forward<Ts>(args)...,'\n');}void flush(){output->flush();}}
#pragma GCC diagnostic pop

#if LOCAL
// give error if std:: versions are used
#define cin cin__
#define cout cout__
#endif

struct Input{
	Input(){ io::input.reset(new io::InputFile(stdin, false)); }
	template<class T> auto& operator>>(T& t){ io::read(t); return *this; }
} cin;
struct Output{
	Output(){ io::output.reset(new io::OutputFile()); }
	template<class T> auto& operator<<(T const& t){ io::write(t); return *this; }
} cout;

template<class T> T read(){
	T result; cin>>result; return result;
}

// } ==== End library FastIO.h ====
//#include"read"

// { ==== Begin library range ====

template<class T>
struct int_iter{
	//using iterator_category = std::random_access_iterator_tag;
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	//using difference_type = std::ptrdiff_t;
	using difference_type = T;
	using pointer = T*;
	using reference = T&;

	T x;
	constexpr int_iter(T x):x{x}{}
	T operator*()const{return x;}
	int_iter& operator++(){ ++x; return *this; }
	int_iter& operator--(){ --x; return *this; }

#define operation(op) \
	int_iter& operator op##=(difference_type y){ x op##= y; return *this; } \
	int_iter friend operator op(int_iter x, difference_type y){ return x op##= y; }
	operation(+) operation(-)
#undef operation
	int_iter friend operator+(difference_type y, int_iter x){ return x += y; }

#define operation(op) \
	auto operator op(int_iter const& other) const{return x op other.x;}
	operation(-) operation(<) operation(>) operation(<=) operation(>=) operation(==) operation(!=)
#undef operation

	T operator[](difference_type y)const{ return x+y; }
};

struct unreachable_iter{
	template<class T, class U,
		class=std::enable_if<
			std::is_same<T, unreachable_iter>::value xor std::is_same<U, unreachable_iter>::value, int>
	> friend bool operator!=(T const& first, U const& sec){ return true; }
};

template<class T> auto range(T first, T last);


template<class A, class B=A>
struct Range{
	A first; B last;
	constexpr Range(A first, B last):first{std::move(first)},last{std::move(last)}{}

	/*
	template<class Container> Range(Container&& container):
		first(std::begin(std::forward<Container>(container))), last(std::end(std::forward<Container>(container))){}
		*/

	// make sure container is not a temporary (TODO?)
	template<class Container> Range(Container& container):
		first(std::begin(container)), last(std::end(container)){}

	constexpr A const& begin() const{return first;}
	constexpr B const& end() const{return last;}
	constexpr auto size() const{ return last-first; }

	Range take(std::size_t len)const{
		return Range{first, std::next(first, len)};
	}
	Range drop(std::size_t len)const{
		return Range{std::next(first, len), last};
	}

	Range const& sort    () const{ std::sort(first, last); return *this; }
	template<class F> Range const& sort_by (F const& compare) const{ std::sort(first, last, compare); return *this; }
	template<class F> Range const& sort_key(F const& key) const{
		std::sort(first, last, [&](auto const& first, auto const& sec){
			return key(first)<key(sec);
		});
		return *this;
	}

	template<class T> Range const& shuffle(T&& engine) const{ std::shuffle(first, last, engine); return *this; }
	Range& unique() { last=std::unique(first, last); return *this; }
	//Range const& reverse() const{ std::reverse(first, last); return *this; }
	auto reverse() const{
		return range(
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
				);
		/*
		return Range<
				typename std::decay<decltype(std::make_reverse_iterator(last))>::type,
				typename std::decay<decltype(std::make_reverse_iterator(first))>::type
		>{
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
		};
		*/
	}

	auto const& assign(Range other) const{
		assert(size()==other.size());
		std::copy(other.first, other.last, first);
		return *this;
	}
	auto const& copy_to(A const& iterator) const{
		std::copy(first, last, iterator);
		return *this;
	}
	auto const& copy_to(Range const& range) const{
		std::copy(first, last, range.first);
		return *this;
	}

	template<class F> auto any  (F const& function) const{ return std::any_of(first, last, function); }
	template<class F> auto all  (F const& function) const{ return std::all_of(first, last, function); }
	template<class F> auto none (F const& function) const{ return std::none_of(first, last, function); }
	template<class F> auto count(F const& function) const{ return std::count_if(first, last, function); }
	template<class F> auto find (F const& function) const{ return std::find_if(first, last, function); }
};


template <typename T>
auto dereferencable(const T& x) -> decltype(void(*x), std::true_type());

std::false_type dereferencable(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  // otherwise won't work properly
		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(dereferencable(first))::value, "value type is neither integral nor dereferencable");
		return Range<T>{first, last};
	}
}

template<class T> auto range(T&& value){
	using T1=typename std::decay<T>::type;
	if constexpr(std::is_integral<T1>::value)
		return Range<int_iter<T1>>{{{}}, std::forward<T>(value)};
	else
		return Range<typename std::decay<decltype(value.begin())>::type>{std::forward<T>(value)};
}


//template<class Container> auto range(Container container){
//	return Range{ std::begin(container), std::end(container) };
//}

template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto infinite_range(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }

// } ==== End library range ====

// { ==== Begin library Int128.h ====

// hack (overriding things in namespace std is undefined behavior!!!)

#if __cplusplus < 201799

namespace std{
	template<> struct is_integral<__int128> : std::true_type {};
	template<> struct is_signed<__int128> : std::true_type {};
	template<> struct is_integral<unsigned __int128> : std::true_type {};
	template<> struct is_unsigned<unsigned __int128> : std::true_type {};
}

#endif

auto& operator<<(std::ostream& o, unsigned __int128 x){
	int64_t const TENPOW18=1000000000000000000;
	if(x<TENPOW18) o<<(int64_t)x;
	else{
		o<<int64_t(x/TENPOW18)<<
			std::setfill('0')<<std::setw(18)
			<<int64_t(x%TENPOW18);
	}
	return o;
}

auto& operator<<(std::ostream& o, __int128 x){
	if(x<0) return o<<'-'<<(unsigned __int128)-x;  // the minimum value causes overflow
	return o<<(unsigned __int128) x;
}

int ctz128(unsigned __int128 a){
	if(a & UINT64_MAX)
		return __builtin_ctzll(uint64_t(a));
	return 64+__builtin_ctzll(uint64_t(a>>64));
}

// } ==== End library Int128.h ====
//#include"PairCompareFirst.h"


__int128 gcd(unsigned __int128 a, unsigned __int128 b){
	/*
	if(a==0) return b;
	if(b==0) return a;
	auto const ctzresult=std::min(ctz128(a), ctz128(b));

	a>>=ctz128(a);
	b>>=ctz128(b);

	while(true){
		if(a>b){
			a-=b;
			a>>=ctz128(a);
		}else if(b>a){
			b-=a;
			b>>=ctz128(b);
		}else{
			return a<<ctzresult;
		}
	}
	*/
	return std::__gcd(a, b);
}

struct EffectivePrimeSet{
	std::vector<__int128> values;

	void add(__int128 value, int safe=0){
		assert(value>0);

		for(int const i: range(0, safe)){
			assert(gcd(values[i], value)==1);
		}

		for(auto const i: range(values.begin()+safe, values.end())){
			while(value%i==0) value/=i;
		}
		if(value==1) return;

		auto iter=std::partition(values.begin()+safe, values.end(), [&](auto const& it){
			return gcd(value, it)==1;
		});
		safe=int(iter-values.begin());

		if(safe==int(values.size())){
			values.push_back(value);
			return;
		}

		auto const p=values.back();

		auto g=gcd(p, value%p); // do one step in advance

		assert(1<g); assert(g<p);  // as such this will always terminate (not sure in how many iterations though)
		values.back()=g;
		add(p/g, int(values.size())-1);
		while(value%g==0) value/=g;
		add(value, safe);
	}
};

void up();
int main(){
	//std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; cin>>numTest;
	while(numTest--) up();
}

double constexpr epsilon=1e-9;
double constexpr maxValue=4e36*(1+epsilon);

void up(){
	int const sizeA=read<int>();
	int const sizeB=read<int>();
	std::vector<__int128> a(sizeA);
	for(auto& it: a) {
		cin>>it;
	}
	std::vector<__int128> b(sizeB);
	for(auto& it: b) {
		cin>>it;
	}
	
	EffectivePrimeSet primes;
	for(auto it: a) primes.add(it);
	for(auto it: b) primes.add(it);

	//debug(primes.values)

	// then "factorize" it...
	
	if(1){
	using Item=std::pair<int, int>; // first: exponent, second: infoIndex (uh ugly code... but C++ is not that strong...)
	std::vector<std::array<std::multiset<Item, std::greater<>>, 2>> data(primes.values.size()); // 0 for a, 1 for b

	struct Element{int primeIndex, exponent;};
	char constexpr REMOVE=0x2;
	struct Info{
		char isB;
		__int128 value;
		std::vector<Element> factors;
	};
	std::vector<Info> info; info.reserve(a.size()+b.size());

	auto const factorizePush=[&](__int128 const value, bool isB){
		std::vector<Element> factors;
		auto value1=value;
		for(int primeIndex=0; value1!=1; primeIndex++){
			auto const p=primes.values[primeIndex];
			int exponent=0;
			while(value1%p==0){
				value1/=p;
				exponent++;
			}
			if(exponent!=0){
				factors.push_back({primeIndex, exponent});
				data[primeIndex][isB].insert(Item{exponent, int(info.size())});
			}
		}
		info.push_back({isB, value, std::move(factors)});
	};

	for(auto x: a) {
		factorizePush(x, false);
	}
	for(auto x: b) {
		factorizePush(x, true);
	}


	std::vector<int> pend; // list of "prime" index
	std::vector<char> inPend(primes.values.size(), true);

	for(int const i: range(0, int(inPend.size()))){
		pend.push_back(i);
	}

	auto const check=[&]{
		assert(int(pend.size())==std::accumulate(begin(inPend), end(inPend), 0));
		for(auto x: pend) assert(inPend[x]);

		for(auto z: data) for(auto t: z) for(auto u: t){
			auto const [exponent, infoIndex]=u;
			assert(info[infoIndex].isB!=REMOVE);
		}

		return true;
	};

	auto const deleteItem=[&](Item x){

		check();

		auto const infoIndex=x.second;
		auto const isB=info[infoIndex].isB;
		assert(isB!=REMOVE); info[infoIndex].isB=REMOVE;
		for(auto [primeIndex, exponent]: info[infoIndex].factors){
			assert(data[primeIndex][isB].find(Item{exponent, infoIndex}) != data[primeIndex][isB].end());
			data[primeIndex][isB].erase(data[primeIndex][isB].find(Item{exponent, infoIndex}));
			if(not inPend[primeIndex]){
				inPend[primeIndex]=true;
				pend.push_back(primeIndex);
			}
		}

		check();
	};

	while(not pend.empty()){

		check();

		auto const i=pend.back(); pend.pop_back();
		assert(inPend[i]); inPend[i]=false;
		if(data[i][0].empty() and data[i][1].empty()) continue;

		if(data[i][0].empty()){
			deleteItem(*data[i][1].begin()); continue;
		}
		if(data[i][1].empty()){
			deleteItem(*data[i][0].begin()); continue;
		}
		if(data[i][0].begin()->first>data[i][1].begin()->first){
			deleteItem(*data[i][0].begin()); continue;
		}
		if(data[i][1].begin()->first>data[i][0].begin()->first){
			deleteItem(*data[i][1].begin()); continue;
		}
	}

	a.clear(); b.clear();
	for(auto x: info) if(x.isB!=REMOVE){
		(x.isB ? b: a).push_back(x.value);
	}



	}

	if(a.empty() or b.empty()){
		cout<<"NO\n";
		return;
	}

	if(0){
	while(true){
		if(a.empty() or b.empty()){
cannot:
			cout<<"NO\n";
			return;
		}

		bool done_anything=false;
		for(auto& p_: primes.values){
			auto const p=p_;

			auto const check=[&](int exponent){
				assert(not a.empty());
				assert(not b.empty());
				if(std::log(double(p))*exponent>std::log(maxValue)) return false;
				__int128 factor=1;
				for(int _=exponent; _--;) factor*=p;
				for(auto x: a) if(x%factor==0) return true;
				return false;
			};

			int exponent=0;

			// 2**(1<<7) = 2**128 > maxValue, okay
			for(int step=1<<7; step; step>>=1) if(check(exponent+step)) exponent+=step;

			// now exponent is the order of p in lcm(a)

			__int128 factor=1;
			for(int _=exponent; _--;) factor*=p;
			if(exponent>0 and std::none_of(begin(b), end(b), [&](auto const& it){
				return it%factor==0;
			})){
				// orderB<orderA. Must remove the top order items from a
				a.erase(std::remove_if(begin(a), end(a), [&](auto const& it){
					return it%factor==0;
				}), end(a));
				if(a.empty()) goto cannot;
				done_anything=true;
			}else{
				// orderB might be > orderA. Need to check

				if(std::log(double(p))*(exponent+1)<=std::log(maxValue)){
					factor*=p; // now factor=p**(exponent+1)
					auto const iter=std::remove_if(begin(b), end(b), [&](auto const& it){
						return it%factor==0;
						// if true: orderB>orderA. Must remove it from b
					});
					if(iter!=end(b)){
						b.erase(iter, end(b));
						if(b.empty()) goto cannot;
						done_anything=true;
					}
				}
			}

			if(exponent==0) p_=-1; // this "prime" factor is no longer necessary
		}

		primes.values.erase(std::remove(begin(primes.values), end(primes.values), -1), end(primes.values));
		

		if(not done_anything){
			// at this point, the remaining set has equal LCM
			break;
		}
	}
	}

	cout<<"YES\n";
	cout<<a.size()<<' '<<b.size()<<'\n';
	for(auto x: a) cout<<x<<' ';
	cout<<'\n';
	for(auto x: b) cout<<x<<' ';
	cout<<'\n';
}


// time-limit: 10000
// problem-url: https://codeforces.com/contest/1656/problem/H